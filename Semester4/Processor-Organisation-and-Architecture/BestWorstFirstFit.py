print("Name : Jash Parikh")
print("Roll number : C065")
print("SAP ID: 60004220080")
print("                  MEMORY ALLOCATION                   ")
def firstFit(blockSize, m, processSize, n,total): 
	allocation = [-1] * n
	sum=0
	for i in range(n): 
		for j in range(m): 
			if blockSize[j] >= processSize[i]: 
				allocation[i] = j 
				blockSize[j]=0
				break
	print(" Process No. Process Size	 Block no.") 
	for i in range(n): 
		print(" ", i + 1, "		 ", processSize[i], 
						"		 ", end = " ") 
		if allocation[i] != -1: 
			print(allocation[i] + 1)
			sum+=processSize[i]
		else: 
			print("Not Allocated")
	print("Memory utilization:",sum/total*100,"%")
def bestFit(blockSize, m, processSize, n,total):  
	allocation = [-1] * n
	sum=0
	for i in range(n): 
		bestIdx = -1
		for j in range(m): 
			if blockSize[j] >= processSize[i]: 
				if bestIdx == -1: 
					bestIdx = j 
				elif blockSize[bestIdx] > blockSize[j]: 
					bestIdx = j  
		if bestIdx != -1:  
			allocation[i] = bestIdx 
			blockSize[bestIdx]=0

	print("Process No. Process Size	 Block no.") 
	for i in range(n): 
		print(i + 1, "		 ", processSize[i], 
								end = "		 ") 
		if allocation[i] != -1: 
			print(allocation[i] + 1)
			sum+=processSize[i]
		else: 
			print("Not Allocated")
	print("Memory utilization:",sum/total*100,"%")
def worstFit(blockSize, m, processSize, n,total): 
	allocation = [-1] * n
	sum=0
	for i in range(n): 
		wstIdx = -1
		for j in range(m): 
			if blockSize[j] >= processSize[i]: 
				if wstIdx == -1: 
					wstIdx = j 
				elif blockSize[wstIdx] < blockSize[j]: 
					wstIdx = j 
		if wstIdx != -1: 
			allocation[i] = wstIdx  
			blockSize[wstIdx]=0 

	print("Process No. Process Size Block no.") 
	for i in range(n): 
		print(i + 1, "		 ", 
			processSize[i], end = "	 ") 
		if allocation[i] != -1: 
			print(allocation[i] + 1)
			sum+=processSize[i]
		else: 
			print("Not Allocated")
	print("Memory utilization:",sum/total*100,"%")

if __name__ == '__main__':
    blockSize = [100, 500, 200, 300, 600]
    l1=input("Enter array : ").split(" ")
    l1=[int(x) for x in l1]
    total=0
    for i in blockSize:
        total+=i
    processSize=l1
    print(l1)
    m = len(blockSize) 
    n = len(processSize)
    print("First fit:")
    firstFit(blockSize, m, processSize, n,total)
    blockSize = [100, 500, 200, 300, 600] 
    print("Best fit:")
    bestFit(blockSize, m, processSize, n,total)
    blockSize = [100, 500, 200, 300, 600] 
    print("Worst fit:")
    worstFit(blockSize, m, processSize, n,total)
	
