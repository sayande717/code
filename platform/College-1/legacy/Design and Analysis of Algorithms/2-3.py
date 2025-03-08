import numpy

def strassenMultiplication(matrix1, matrix2):
    matrixLength = len(matrix1)
    # Base case: simply multiply and return if it is a 1x1 matrix
    if matrix1.shape == (1,1):
        return numpy.dot(matrix1,matrix2)
    
    # Calculating intermediates
    mid = matrixLength // 2
    a = matrix1[:mid,:mid]
    b = matrix1[:mid,mid:]
    c = matrix1[mid:,:mid]
    d = matrix1[mid:,mid:]
    e = matrix2[:mid,:mid]
    f = matrix2[:mid,mid:]
    g = matrix2[mid:,:mid]
    h = matrix2[mid:,mid:]
    
    # recursively calculating intermediates
    p1 = strassenMultiplication(a,(f-h))
    p2 = strassenMultiplication((a+b),h)
    p3 = strassenMultiplication((c+d),e)
    p4 = strassenMultiplication(d,(g-e))
    p5 = strassenMultiplication((a+d),(e+h))
    p6 = strassenMultiplication((b-d),(g+h))
    p7 = strassenMultiplication((a-c),(e+f))
    
    # calculating resulting submatrices    
    c11 = (p5+p4-p2+p6)
    c12 = (p1+p2)
    c21 = (p3+p4)
    c22 = (p1+p5-p3-p7)
    
    topHalf = numpy.hstack((c11,c12))
    bottomHalf = numpy.hstack((c21,c22))
    finalMatrix = numpy.vstack((topHalf,bottomHalf))
    return finalMatrix
  
def main():
    matrix1 = numpy.array([[1,3,5,7],
                        [2,4,6,8],
                        [9,11,13,15],
                        [10,12,14,16]])
    
    matrix2 = numpy.array([[17,19,21,23],
                        [18,20,22,24],
                        [25,27,29,31],
                        [26,28,30,32]])
    
    print("Matrix given according to question:")
    print(f"Matrix 1: \n{matrix1}")
    print(f"Matrix 2: \n{matrix2}")
    resultMatrix = strassenMultiplication(matrix1,matrix2)
    print(f"\nResult: \n {resultMatrix}")

main()