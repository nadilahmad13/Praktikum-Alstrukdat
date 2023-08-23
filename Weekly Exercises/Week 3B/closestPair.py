def closestPair(arr):
    # set minDiff
    if (arr[0] > arr[1]):
        minDiff = arr[0] - arr[1]
        p1,p2 = arr[1],arr[0]
    else:
        minDiff = arr[1] - arr[0]
        p1,p2 = arr[0],arr[1]

    for i in range (len(arr)):
        for j in range (i+1,len(arr)):
            if (arr[i] > arr[j]):
                diff = arr[i] - arr[j]
            else:
                diff = arr[j] - arr[i]

            if (diff < minDiff):
                minDiff = diff
                p1,p2 = arr[i],arr[j]
    
    return p1,p2

# Driver Code
arr = [5,3,10,11,20,19]
print(closestPair(arr))