def ipv4_mask(cidr):
    mask = 2**32 - 2**(32- int(cidr))
    return (mask >>sh & 0xff for sh in (24,16,8,0))

def ipv4_bytes(ip):
    return (int(b) for b in ip.split('.'))

def ipv4_cidr_member_of(ip1, ip2):
    ip2, m = ip2.split('/')
    return not any((a ^ b) & m 
                   for a, b, m in 
                   zip(ipv4_bytes(ip1), 
                       ipv4_bytes(ip2), 
                       ipv4_mask(m)))

def ipv4_cidr_range_bytes(ip):
    ip, m = ip.split('/')
    ip    = list(ipv4_bytes(ip))
    m     = list(ipv4_mask(m))
    start = [ b &  m         for b, m in zip(ip, m)]
    end   = [(b | ~m) & 0xff for b, m in zip(ip, m)]
    return start, end

#print(ipv4_mask("2.225.255.0"))

tempString = input()
n,k = tempString.split(" ")
n = int(n)
k= int(k)
netMask = list()
ipEnd = list()
location = list()

for i in range(n):
    inputString = input()
    ipl = inputString.split(" ")
    netMask.append(ipl[0].split("/")[0])
    ipEnd.append(ipl[1].split("/")[0])
    location.append(ipl[2])


for i in range(k):
    ipToTest = input()
    flag = 0
    for i in range(n):
        if(ipv4_cidr_member_of(ipToTest,netMask[i])):
            print(location[i])
            flag =1
            break
    if flag == 1:
        print("None")
       
        

        

