#!/user/bin/python3
# -*- coding: utf-8 -*-
"""
Created on Mon Nov 12 19:18:17 2018

@author: Carlos Carbajal
"""
import sys as s

bArr=[]
pArr=[]
turnS=["Turnaround times:"]
waitS=["Waiting times:"]
pStr=[]
separator= ' '

def readFile(file):
    f=open(file,"r")
    for i in range(int(f.readline())):
        line=f.readline()
        line.replace("\n","")
        data=line.split(" ")
        bArr.append(int(data[0]))
        pArr.append(int(data[1]))
    f.close()

def sortP(arr1):
<<<<<<< HEAD
    for i in range(len(arr1)):
        idx=i
        for j in range(i+1, len(arr1)):
            if arr1[idx] > arr1[j]:
                idx = j
        arr1[i], arr1[idx] = arr1[idx], arr1[i]
        bArr[i], bArr[idx] = bArr[idx], bArr[i]
=======
    for i in range(len(arr1)): 
	idx = i 
	for j in range(i+1, len(arr1)): 
		if arr1[idx] > arr1[j]:
			idx = j 
	arr1[i], arr1[idx] = arr1[idx], arr1[i] 
	bArr[i], bArr[idx] = bArr[idx], bArr[i]

>>>>>>> 7a37dbe3dec6efd6e4655c3b3cc8514200adae45

def fcfs(arr1):
    t=0
    wait=0
    turn=0
    for i in range(len(arr1)):
        wait+=t
        waitS.append(t)
        t+=arr1[i]
        turn+=t
        pStr.append(("P%d[%d] |"%(i,arr1[i])))
        turnS.append(t)
    print(separator.join(pStr))
    print(turnS)
    print(waitS)
    print("Av. Turnaround time: "+str(turn/len(arr1))+
	  "\n"+ "Av. Waiting time: "+str(wait/len(arr1))+"\n")

def sjf(arr1):
    arr1.sort()
    t=0
    wait=0
    turn=0
    for i in range(len(arr1)):
        wait+=t
        waitS.append(t)
        t+=arr1[i]
        turn+=t
        pStr.append(("P%d[%d] |"%(i,arr1[i])))
        turnS.append(t)

    print(separator.join(pStr))
    print(turnS)
    print(waitS)
    print("Av. Turnaround time: " + str(turn/len(arr1))
          +"\n"+ "Av. Waiting time: "+ str(wait/len(arr1)) +"\n")


def priority(arr1,arr2):
    sortP(arr2)
    t=0
    wait=0
    turn=0
    for i in range(len(arr1)):
        wait+=t
        waitS.append(t)
        t+=arr1[i]
        turn+=t
        pStr.append(("P%d[%d] |"%(i,arr1[i])))
        turnS.append(t)

    print(separator.join(pStr))
    print(turnS)
    print(waitS)
    print("Av. Turnaround time: " + str(turn/len(arr1))
          +"\n"+ "Av. Waiting time: "+ str(wait/len(arr1)) +"\n")

def main():
    if(len(s.argv)==3):
        readFile(s.argv[2])
        #print (bArr)
        if(s.argv[1]=="-fcfs"):
            print("You choosed the First-Come,"+
                  "First-Served algorithm, the file to open is: %s \n" %s.argv[2])
            fcfs(bArr)
        if(s.argv[1]=="-sjf"):
            print("You choosed the Shortest Job First "+
                  "algorithm, the file to open is: %s \n" %s.argv[2])
            sjf(bArr)
        if(s.argv[1]=="-rr"):
            print("You choosed the Round Robin "+
                  "algorithm, the file to open is: %s \n" %s.argv[2])
        if(s.argv[1]=="-p"):
            print("You choosed the Priority "+
                  "algorithm, the file to open is: %s \n" %s.argv[2])
            priority(bArr,pArr)
        else:
            print("****** UNKOWN COMMAND! ******")
    else:
            print("****** UNKOWN COMMAND! ******")
            
main()    
