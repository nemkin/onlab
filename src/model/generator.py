import os
import json
import shutil

generated_directory_path = './generated'

entities_directory_path = './generated/entities'
database_directory_path = './generated/database'

type_model_file_path = 'descriptors/type_model.json'
data_model_file_path = 'descriptors/data_model.json'

with open(type_model_file_path) as type_model_file:

    type_model = json.load(type_model_file)

with open(data_model_file_path) as data_model_file:

    data_model = json.load(data_model_file)

def cpp_class_name(class_model):

    return ''.join([part.capitalize() \
        for part in class_model['class'].split('_')])

def cpp_class_members(class_model):
    
    global type_model
    global data_model

    ret = []
  
    ret += [{'name': 'id', 'type': 'id'}]
    ret += class_model['members']
    for reference in class_model['references']:

        ret += [{\
            'name': reference['class'] + '_id' if 'name' not in reference else reference['name'],\
            'type': 'reference'\
        }]

    ret += data_model['default']['members'] 
   
    return ret 

def generate_header(class_model):

    global type_model
    global data_model

    header = ''
     
    header += '#pragma once\n'
    header += '\n'
    header += '#ifndef __' + class_model['class'].upper() + '__H__\n'
    header += '#define __' + class_model['class'].upper() + '__H__\n'
    header += '\n'
    header += '#include <string>\n'
    header += '\n'
    header += 'namespace chronos {\n'
    header += '\n'
    header += 'class ' + cpp_class_name(class_model) + ' {\n'
    header += '\n'
    header += 'public:\n'
    header += '\n'
    header += '    ' + cpp_class_name(class_model) + '();\n'
    header += '\n'
    header += '    ' + cpp_class_name(class_model) + '(\n'
  
    for i, member in enumerate(cpp_class_members(class_model)):
        
        header +=\
            '        ' +\
            type_model[member['type']]['cpp'] +\
            ' p_' +\
            member['name'] +\
            (',' if i != len(cpp_class_members(class_model))-1 else '') +\
            '\n'
    
    header += '    );\n'
    header += '\n'
    
    for member in cpp_class_members(class_model):
    
        header +=\
            '    ' +\
            type_model[member['type']]['cpp'] +\
            ' ' +\
            member['name'] +\
            '() const;\n'
    
    header += '    std::string to_string() const;\n'
    header += '\n'
    header += 'private:\n'
    header += '\n'
    
    for member in cpp_class_members(class_model):
    
        header +=\
            '    ' +\
            type_model[member['type']]['cpp'] +\
            ' _' +\
            member['name'] +\
            ';\n'
    
    header += '\n'
    header += '};\n'
    header += '\n'
    header += '}\n'
    header += '\n'
    header += '#endif //__' + class_model['class'].upper() + '__H__\n'
    header += '\n'
    
    return header   

def generate_source(class_model):

    global type_model
    global data_model

    source = ''
     
    source += '#include "' + class_model['class'] + '.h"\n'
    source += '\n'
    source += '#include <sstream>\n'
    source += '\n'
    source += 'using namespace chronos;\n'
    source += '\n'
    source += cpp_class_name(class_model) + '::' + cpp_class_name(class_model) + '(\n'
    source += ') :\n'
    
    for i, member in enumerate(cpp_class_members(class_model)):
    
        source +=\
            '    _' +\
            member['name'] +\
            '(' +\
            type_model[member['type']]['default_value'] +\
            ')' +\
            (',' if i != len(cpp_class_members(class_model))-1 else ' {') +\
            '\n'
   
    source += '\n'
    source += '}\n'
    source += '\n'
    source += cpp_class_name(class_model) + '::' + cpp_class_name(class_model) + '(\n' 

    for i, member in enumerate(cpp_class_members(class_model)):
        
        source +=\
            '    ' +\
            type_model[member['type']]['cpp'] +\
            ' p_' +\
            member['name'] +\
            (',' if i != len(cpp_class_members(class_model))-1 else '') +\
            '\n'
    
    source += ') :\n'
    
    for i, member in enumerate(cpp_class_members(class_model)):
    
        source +=\
            '    _' +\
            member['name'] +\
            '(p_' +\
            member['name'] +\
            ')' +\
            (',' if i != len(cpp_class_members(class_model))-1 else ' {') +\
            '\n'

    source += '\n'
    source += '}\n'
    source += '\n' 

    for member in cpp_class_members(class_model):
    
        source +=\
            type_model[member['type']]['cpp'] +\
            ' ' +\
            cpp_class_name(class_model) +\
            '::' +\
            member['name'] +\
            '() const {\n' +\
            '\n' +\
            '    return _' +\
            member['name'] +\
            ';\n' +\
            '}\n' +\
            '\n'
             
    source += 'std::string ' + cpp_class_name(class_model) + '::to_string() const {\n'
    source += '\n'
    source += '    std::stringstream ss;\n'
    source += '\n'

    max_len = max(map(len, [member['name'] for member in cpp_class_members(class_model)]))

    source +=\
        '    ss << "' +\
        class_model['class'] +\
        ' ' +\
        ' ' * (max_len - len(class_model['class'])) +\
        ' "' +\
        '     ' +\
        ' ' * max_len +\
        ' << std::endl;\n'

    for member in cpp_class_members(class_model):

        source +=\
            '    ss << "' +\
            member['name'] +\
            ':' +\
            ' ' * (max_len - len(member['name'])) +\
            ' "' +\
            ' << _' +\
            member['name'] +\
            ' ' * (max_len - len(member['name'])) +\
            ' << std::endl;\n'

    source += '\n'
    source += '    return ss.str();\n'
    source += '}\n'
    source += '\n'

    return source

if __name__ == '__main__':

    shutil.rmtree(generated_directory_path)

    os.makedirs(entities_directory_path)
    os.makedirs(database_directory_path)

    for class_model in data_model['classes']:

        with open(os.path.join(entities_directory_path, class_model['class'] + '.h'), 'w+') as header_file:

            header_file.write(generate_header(class_model))

        with open(os.path.join(entities_directory_path, class_model['class'] + '.cpp'), 'w+') as source_file:

            source_file.write(generate_source(class_model))
