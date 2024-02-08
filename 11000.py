#백준 온라인 저지 1100 하얀 칸
count = 0 # 하얀칸위의 말의 개수를 세는 변수
white = 0 # 0 /1 토글 첫번째 줄은 짝수번 문자가 흰색 , 두번째줄은 홀수번

#반복문 갈기기
for _ in range(8):
    line = input()
     #입력받은 문자열에서 8번 흰색 칸에 말이 있는지 검사한다.
    for i in range(8):
        if line[i] == 'F' and i%2==white:
            count+=1
    white = (white+1)%2

print(count)
