class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        #minimum s-1 spaces per line for s words 
        word_list = []
        word_line=[]
        num_words=0.0
        s=''
        last = False
        for index11,word in enumerate(words):
            len_line = ''.join(word_line)
            if(len(len_line+word)+num_words > maxWidth): # see if we go over
                if(num_words > 1):
                    spaces=(maxWidth-len(len_line))/(num_words-1) # calculate number of spaces that we need
                else:
                    spaces=float(maxWidth-len(word_line[0]))       # one word fits the whole line
                s=''
                if not spaces.is_integer():
                    keep_track = maxWidth-len(len_line)
                    while not spaces.is_integer(): #check if we need uneven number of spaces
                        s+=word_line[0]+' '*ceil(spaces)
                        keep_track-=ceil(spaces)
                        print(ceil(spaces),keep_track)
                        num_words-=1
                        spaces = (keep_track)/float((num_words-1))
                        #print(spaces)
                        word_line=word_line[1:]
                else:
                    s+=word_line[0]+' '*floor(spaces)
                    word_line=word_line[1:]
                for index,val in enumerate(word_line[:-1]): #append all even number of middle spaces
                        s+=val+' '*floor(spaces)
                if word_line:
                    s+=word_line[-1]                        #append last word
                word_list.append(s) #FINISHED LINE
                
                word_line.clear() #RESET VALUES
                word_line.append(word) 
                num_words=1
                if index11== len(words)-1:
                    last = True
            else:
                    word_line.append(word)
                    num_words+=1
                    if index11== len(words)-1:
                        last = True
        if last:
            word_list.append(' '.join(word_line)+' '*(maxWidth-len(' '.join(word_line))))
        return word_list
            
        
