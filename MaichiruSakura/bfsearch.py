import os 
#46 00 5e 00 32 00 00 00 0f 00 00 00 01 02 fe ff 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 54 cc de db af b8 41 00 54 81 77 97 e3 82 dc 82 b5 82 cd 88 c8 8a 4f 82 c8 90 6c 82 a9 82 e7 81 42 8b d8 93 f7 8b b3 8e 74 82 cd 89 e4 82 aa 89 b6 8e 74 81 78 00
#4600类型为文本，5e00为整个段长度
for f in os.listdir('BIN'):
    print(f)
    with open('BIN/'+f,'rb') as ff:
        bs=ff.read()
    idx=0
    while idx<len(bs)-4:
        if bs[idx]==0x46 and bs[idx+1]==0:
            length=bs[idx+2]+bs[idx+3]*255
            if length==0:
                idx+=1 
                continue
            elif length<=40:
                idx+=length
                continue

            d=bs[idx:idx+length]
            text=d[40:] #中间可能用0分割多个句子
            text=text[:-1]#末尾0
            if text.find(b'\x00')!=-1:
                idx+=length
                continue
             
            try:
                text.decode('cp932')
                
                with open('text/'+f+'.txt','a',encoding='utf8') as ff:
                    print('○'+str(idx)+'|'+str(length)+'○'+text.decode('cp932'),file=ff) 
                    print('●'+str(idx)+'|'+str(length)+'●'+text.decode('cp932'),file=ff) 
                    print('',file=ff) 
            except:
                print(hex(idx),length,text)
            idx+=length
        else:
            idx+=1