from time import time
start_time = time()

# def longestCommonSubsequence(text1: str, text2: str) -> int:
#     lcs=[[[] for x in range(len(text1)+1)] for y in range(len(text2)+1)]

#     for i in range(1, len(text2)+1):
#         for j in range(1, len(text1)+1):
#             if text2[i-1]==text1[j-1]:
#                 lcs[i][j]= [text2[i-1]]+ lcs[i-1][j-1]
#             else:
#                 lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1], key=len)
#     return len(lcs[-1][-1])
# text1="aasdvskskdfjjf"
# text2="alsdjlajfklshdfhladks"
# print(longestCommonSubsequence(text1, text2))


""" def longestCommonSubsequence(text1: str, text2: str):
    lcs=[[[None, 0, None, None] for x in range(len(text1)+1)] for y in range(len(text2)+1)]

    for i in range(1,len(text2)+1):
        for j in range(1, len(text1)+1):
            if text2[i-1]==text1[j-1]:
                lcs[i][j]=[text2[i-1], lcs[i-1][j-1][1]+1, i-1, j-1]
            else:
                if lcs[i-1][j][1] > lcs[i][j-1][1]:
                    lcs[i][j]=[None, lcs[i-1][j][1], i-1, j]
                else:
                    lcs[i][j]=[None, lcs[i][j-1][1], i, j-1]
    return buildSequence(lcs)

def buildSequence(lcs):
    sequence=[]
    i=len(lcs)-1
    j=len(lcs[0])-1
    while i!=0 and j!=0:
        currentEntry=lcs[i][j]
        if currentEntry[0] is not None:
            sequence.append(currentEntry[0])
        i=currentEntry[2]
        j=currentEntry[3]
    #return list(reversed(sequence))
    return len(sequence)
text1="aasdvskskdfjjf"
text2="alsdjlajfklshdfhladks"
print(longestCommonSubsequence(text1, text2)) """

""" 
void relax(int &a, int b) {                   //relaxation routine
  if (a < b) a = b;
}
 
  memset(lcs, -63, sizeof(lcs));              //fill the DP results array with negative infinity
  lcs[0][0] = 0;                              //set DP base: (0,0)->0
  for (int i = 0; i<=n1; i++)
    for (int j = 0; j<=n2; j++):              //iterate through all states
      int tres = lcs[i][j];
      relax(lcs[i+1][j], tres);               //try transition of type 1
      relax(lcs[i][j+1], tres);               //try transition of type 2
      if (str1[i] == str2[j]):                 //and if next symbols are the same
        relax(lcs[i+1][j+1], tres + 1);       //then try transition of type 3
  int answer = lcs[n1][n2]; """

def longestCommonSubsequence(text1: str, text2: str):
    # If text1 doesn't reference the shortest string, swap them.
    if len(text2) < len(text1):
        text1, text2 = text2, text1
    # The previous column starts with all 0's and like before is 1
    # more than the length of the first word.
    previous = [0] * (len(text1) + 1)
    # Iterate up each column, starting from the last one.
    for col in reversed(range(len(text2))):
        # Create a new array to represent the current column.
        current = [0] * (len(text1) + 1)
        for row in reversed(range(len(text1))):
            if text2[col] == text1[row]:
                current[row] = 1 + previous[row + 1]
            else:
                current[row] = max(previous[row], current[row + 1])
        # The current column becomes the previous one.
        previous = current

    # The original problem's answer is in previous[0]. Return it.
    return previous[0]
text1="aasdvskskdfjjf"
text2="alsdjlajfklshdfhladks"
print(longestCommonSubsequence(text1, text2))

passed_time = time() - start_time
print(f"It took {passed_time}")