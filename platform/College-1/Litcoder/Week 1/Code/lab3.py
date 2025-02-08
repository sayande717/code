def find_subarray(arr):
    arr = arr.split(' ')
    sum = 0
    arr_len = len(arr)
    if (arr_len > 10):
        print("Array size must be between 1 and 10",end='')
        return
    try:
        for index in range(arr_len):
            element = int(arr[index])
            if(element<-10 or element>10):
                print("Array elements must be from -10 to 10")
            sum = sum + element
    except ValueError:
        print("Array elements must be integers",end='')
        return
    print((sum==0))
    
    print(arr_len,end='')
find_subarray(input())
