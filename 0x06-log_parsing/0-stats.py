#!/usr/bin/python3
import sys 
  
responses = [200, 301, 400, 401, 403, 404, 405, 500]
responsesCounter = [0, 0, 0, 0, 0, 0, 0, 0]
TenCounter = 0
TotalSize = 0

for line in sys.stdin:
    if TenCounter != 10:
        SplitedLine = line.split()[-2:]
        TotalSize += int(SplitedLine[1])
        
        if int(SplitedLine[0]) in responses:
            responsesCounter[responses.index(int(SplitedLine[0]))] += 1
    
    else:
        print(f'File size: {TotalSize}')
        for element in responses:
            print("{}: {}".format(element, responsesCounter[responses.index(int(element))]))



else:
    responsesCounter = [0, 0, 0, 0, 0, 0, 0, 0]
    TenCounter = 0
    TotalSize = 0

