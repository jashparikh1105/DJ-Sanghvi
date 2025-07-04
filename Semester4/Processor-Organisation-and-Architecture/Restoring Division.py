print("Name : Jash Parikh")
print("Roll number : C065")
print("SAP ID: 60004220080")
print("                    Restoring Division                   ")
def add(A, M):
	carry = 0
	Sum = ''

	# Iterating through the number A. Here, it is assumed that the length of both the numbers is same
	for i in range (len(A)-1, -1, -1):

		# Adding the values at both the indices along with the carry
		temp = int(A[i]) + int(M[i]) + carry

		# If the binary number exceeds 1
		if (temp>1):
			Sum += str(temp % 2)
			carry = 1
		else:
			Sum += str(temp)
			carry = 0

	# Returning the sum from 
	# MSB to LSB
	return Sum[::-1] #reverses the list

# Function to find the twos complement of the given binary number
def complement(m):
	M = ''
	for i in range (0, len(m)):

		# Computing the complement
		M += str((int(m[i]) + 1) % 2)

	# Adding 1 to the computed value
	M = add(M, '0001')
	return M
	
# Function to find the quotient and remainder using the Restoring Division Algorithm
def restoringDivision(Q, M, A):

	# Computing the length of the number
	count = len(M)

	# Printing the initial values of the accumulator, dividend and divisor
	print ('Initial Values: A:', A, 
		' Q:', Q, ' M:', M)

	# The number of steps is equal to the length of the binary number
	while (count):

		# Printing the values at every step
		print ("\nstep:", len(M)-count + 1, end = '')
		
		# Step1: Left Shift, assigning LSB of Q to MSB of A.
		print (' Left Shift and Subtract: ', end = '')
		A = A[1:] + Q[0]

		# Step2: Subtract the Divisor from A (Perform A - M).
		comp_M = complement(M)

		# Taking the complement of M and adding to A.
		A = add(A, comp_M)
		print(' A:', A)
		print('A:', A, ' Q:', Q[1:]+'_', end ='')
		
		if (A[0] == '1'):

			# The step is unsuccessful and the quotient bit will be '0'
			Q = Q[1:] + '0'
			print(' ')

			# Restoration of A is required
			A = add(A, M)
			print ('A:', A, ' Q:', Q, ' -Restoration')
			
		else:

			# Else, the step is successful and the quotient bit will be '1'
			Q = Q[1:] + '1'
			print(' ')

			# No Restoration of A.
			print ('A:', A, ' Q:',
				Q, ' -No Restoration')
		count -= 1

	# Printing the final quotient and remainder of the given dividend and divisor. 
	print ('\nQuotient(Q):', Q,
		' Remainder(A):', A)


dividend = input("Enter divident in binary: ")
divisor = input("Enter divisor in binary: ")

accumulator = '0' * len(dividend)

restoringDivision(dividend,divisor,accumulator)
