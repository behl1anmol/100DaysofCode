s,nat = input().split()
s= int(s)
nat = int(nat)
hur = list(map(int,input().strip().split()))

m = max(hur)

if nat>=m:
    print("0")
else:
    print(m-nat)