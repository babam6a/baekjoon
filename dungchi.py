# preprocessing
num = int(input().rstrip())
source = []
ans = [0] * num
#print(" ".join(map(str,ans)))
for i in range(num) :
	a,b = map(int,input().rstrip().split(" "))
	source.append([a,b,i])

# main code
def heapify(arr, n, i, j):
      # Find largest among root and children
      largest = i
      l = 2 * i + 1
      r = 2 * i + 2
  
      if l < n and arr[i][j] < arr[l][j]:
          largest = l
  
      if r < n and arr[largest][j] < arr[r][j]:
          largest = r
  
      # If root is not largest, swap with largest and continue heapifying
      if largest != i:
          arr[i], arr[largest] = arr[largest], arr[i]
          heapify(arr, n, largest, j)
  
  
def heapSort(arr, j):
	n = len(arr)
  
	# Build max heap
	for i in range(n//2, -1, -1):
		heapify(arr, n, i, j)
  
	for i in range(n-1, 0, -1):
        	# Swap
		arr[i], arr[0] = arr[0], arr[i]
  
          	# Heapify root element
		heapify(arr, i, 0, j)
	arr.reverse()
	return arr
  
  
if __name__ == "__main__" :
	source1 = source.copy()
	source2 = source.copy()
	height = heapSort(source1, 0)
	weight = heapSort(source2, 1)
	n = len(source)
	print("Sorted array is")
	for i in range(n):
		print(height[i], end = '')
	print()
	for i in range(n) :
		print(weight[i], end = '')
	print()
