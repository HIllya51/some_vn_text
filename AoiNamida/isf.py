a=b'\x81\x40\x81\x40\x81\x41\x81\x42\x81\x45\x81\x48\x81\x49\x81\x69\x81\x6A\x81\x75\x81\x76\x82\x4F\x82\x50\x82\x51\x82\x52\x82\x53\x82\x54\x82\x55\x82\x56\x82\x57\x82\x58\x82\xA0\x82\xA2\x82\xA4\x82\xA6\x82\xA8\x82\xA9\x82\xAA\x82\xAB\x82\xAC\x82\xAD\x82\xAE\x81\x40\x82\xB0\x82\xB1\x82\xB2\x82\xB3\x82\xB4\x82\xB5\x82\xB6\x82\xB7\x82\xB8\x82\xB9\x82\xBA\x82\xBB\x82\xBC\x82\xBD\x82\xBE\x82\xBF\x82\xC0\x82\xC1\x82\xC2\x82\xC3\x82\xC4\x82\xC5\x82\xC6\x82\xC7\x82\xC8\x82\xC9\x82\xCA\x82\xCB\x82\xCC\x82\xCD\x82\xCE\x82\xD0\x82\xD1\x82\xD3\x82\xD4\x82\xD6\x82\xD7\x82\xD9\x82\xDA\x82\xDC\x82\xDD\x82\xDE\x82\xDF\x82\xE0\x82\xE1\x82\xE2\x82\xE3\x82\xE4\x82\xE5\x82\xE6\x82\xE7\x82\xE8\x82\xE9\x82\xEA\x82\xEB\x82\xED\x82\xF0\x82\xF1\x83\x41\x83\x43\x83\x45\x83\x47\x83\x49\x83\x4A\x83\x4C\x83\x4E\x83\x50\x83\x52\x83\x54\x83\x56\x83\x58\x83\x5A\x83\x5C\x83\x5E\x83\x60\x83\x62\x83\x63\x83\x65\x83\x67\x83\x69\x83\x6A\x82\xAF\x83\x6C\x83\x6D\x83\x6E\x83\x71\x83\x74\x83\x77\x83\x7A\x83\x7D\x83\x7E\x83\x80\x83\x81\x83\x82\x83\x84'


table=a.decode('cp932')
print(table) 
import os
for f in os.listdir(r'C:\Users\wcy\Downloads\aoi\isf_unpack'):
    with open(r'C:\Users\wcy\Downloads\aoi\isf_unpack\\'+f,'rb') as ff:
        bs=ff.read()
    with open('isf_text/'+f,'w',encoding='utf8') as ff:
        idx=0
        ii=0
        while True:
            idx=bs.find(b'\x80\x06\x00\xff',idx)
            if idx<0:
                break
            idx+=4 
            collect=''
            i=0
            while True:
                if bs[idx+i]==0:break
                b=bs[idx+i]
                if b<len(table):
                    collect+=table[b] 
                    i+=1
                else:
                    collect=collect+bs[idx+i:idx+i+2].decode('cp932')
                    i+=2
            print(ii,collect,file=ff )
            ii+=1
            