def encryptNumber(inNum):
    try:
        if(int(inNum)<0):
            print("Enter positive 4-digit integer",end='')
            return
        elif(len(inNum)<4):
            return
        elif(len(inNum)<4):
            print("Provided input is less than 4, enter four digit integers",end='')
            return
        elif(len(inNum)>4):
            print("Provided input is more than 4, enter four digit integers",end='')
    except(ValueError):
        print("Enter only integer value",end='')
        return
    outNum = [0,0,0,0]
    # Encrypt
    for index in range(len(inNum)):
        outNum[index] = int(inNum[index])+5
        if(outNum[index]>=10):
            outNum[index] = outNum[index]%10
    # Swap
    outNum[0],outNum[2] = outNum[2],outNum[0]
    outNum[1],outNum[3] = outNum[3],outNum[1]
    # Print
    for index in range(len(outNum)):
        print(outNum[index],end='')

inNum = str(input())
encryptNumber(inNum)
