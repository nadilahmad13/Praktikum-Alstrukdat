def ordered_array_input(arr,x):
    for i in range(len(arr)):
        if x<arr[i]:
            arr.insert(i,x)
            return arr
        

arr = [1,5,7,9,11,15]
X = 0
while (X != -999):
    X = int(input("Masukkan angka: "))
    if (X == -999):
        break
    else:
        arr = ordered_array_input(arr,X)
        print(arr)