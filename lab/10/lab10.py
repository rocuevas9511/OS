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
turn=0
wait=0

def readFile(file):
    f=open(file,"r")
    for i in range(len(int(f.readline()))):
        line=f.readline()
        line.replace("\n","")
        data=line.split(" ")
        bArr.append(data[0])
        pArr.append(data[1])
    f.close()

def fcfs(arr1):
    t=0
    
    for i in range(len(arr1)):
        wait=t
        waitS.append(t)
        t+=arr1[i]
        turn=t
        pStr.append(("P%d[%d]"%(i,arr1[i])))
        turnS.append(t)
    
    print(''.join(pStr)+"\n"+ ''.join(turnS)+"\n"+
          ''.join(waitS)+"\n"+
          "Av. Turnaround time: " + wait/len(arr1)
          +"\n"+ "Av. Waiting time: "+ turn/len(arr1)+"\n")
    
def sjf(arr1):
    arr1.sort()
    t=0
    
    for i in range(len(arr1)):
        wait=t
        waitS.append(t)
        t+=arr1[i]
        turn=t
        pStr.append(("P%d[%d]"%(i,arr1[i])))
        turnS.append(t)
    
    print(''.join(pStr)+"\n"+ ''.join(turnS)+"\n"+
          ''.join(waitS)+"\n"+
          "Av. Turnaround time: " + wait/len(arr1)
          +"\n"+ "Av. Waiting time: "+ turn/len(arr1)+"\n")

def main():
    if(len(s.argv)==3):
        readFile(s.argv[2])
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
        else:
            print("****** UNKOWN COMMAND! ******")
    else:
            print("****** UNKOWN COMMAND! ******")
            
main()    