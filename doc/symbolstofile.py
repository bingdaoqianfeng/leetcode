#!/usr/bin/python
#encoding=utf-8
 
import os
import os.path
import sys
import getopt
import hashlib
import time
import re
import subprocess

def help():
    print \
    '''
    version 0.1.2
    -----------------------------------------------------------------
    -i input_file 
    ------------------------------------------------------------------
    -o output_file
    ------------------------------------------------------------------
    -l libdir
    ------------------------------------------------------------------
    '''


input_file_name = ''
output_file_name = ''
symbolslibdir = ''

def parse_file(input_file_name,output_file_name,symbolslibdir):
    inputfile = open(input_file_name, "rb")
    outputfile = open(output_file_name,"wb")
    while True:
        oneline = inputfile.readline()
        if not oneline:
            break
        matchsymbols = None

        matchsymbols = re.search(r'#\w\w  pc (\w*)  (\S*)\.so.*', oneline, re.I)
        if matchsymbols:
            print "match one line"
            comandstr = 'addr2line -Cfe %s%s.so %s'%(symbolslibdir,matchsymbols.group(2),matchsymbols.group(1))
            p = subprocess.Popen(comandstr, stdout=subprocess.PIPE, stderr=subprocess.PIPE,shell=True)
            stdoutstr, stderrstr = p.communicate()
            stdoutstr.replace('\n',' ',stdoutstr.count('\n'))
            print stdoutstr
            outputfile.write( stdoutstr + oneline + '\n')
            continue

        matchsymbols = re.search(r'#\w\w pc (\w*)  (\S*)\.so.*', oneline, re.I)
        if matchsymbols:
            print "match one line"
            comandstr = 'addr2line -Cfe %s%s.so %s'%(symbolslibdir,matchsymbols.group(2),matchsymbols.group(1))
            p = subprocess.Popen(comandstr, stdout=subprocess.PIPE, stderr=subprocess.PIPE,shell=True)
            stdoutstr, stderrstr = p.communicate()
            stdoutstr.replace('\n',' ',stdoutstr.count('\n'))
            print stdoutstr
            outputfile.write( stdoutstr + oneline + '\n')
            continue

        matchsymbols = None
        matchsymbols = re.search(r'.*(sysTid=).*', oneline, re.I)
        if matchsymbols:
            outputfile.write("************************************************************************\n")
            outputfile.write(oneline)
            print oneline
            continue
# at last no need to transfor
        outputfile.write(oneline)
        print "not match this line"

    inputfile.close()
    outputfile.close()

def main():
    reload(sys)
    sys.setdefaultencoding('utf-8')
    opts, args = getopt.getopt(sys.argv[1:], "i:o:l:h")
    for op, value in opts:
        if op == '-i':
            input_file_name = value
        elif op == '-o':
            output_file_name = value
        elif op == '-l':
            symbolslibdir = value
            parse_file(input_file_name,output_file_name,symbolslibdir)
            sys.exit()
        elif op == "-h":
            help()
            sys.exit()
    help()
if __name__ == '__main__':
    main()
