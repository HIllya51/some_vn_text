import os
if 0:
    for f in os.listdir('SCRchs'):
        os.system(rf'.\scwextract.exe .\SCRchs\{f} .\textchs\{f}.txt')
else:
    for f in os.listdir('SCRja'):
        os.system(rf'.\scwextract.exe .\SCRja\{f} .\textja\{f}.txt')