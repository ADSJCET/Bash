process_size = int(input('process size'))
resource_size = int(input('resource size'))

max=[]
all=[]

print('Enter Max Matrix')
for i in range(process_size):
    x = []
    for j in range(resource_size):
       x.append(int(input()))

    max.append(x)

print('Enter Alloction Matrix')
for i in range(process_size):
    x = []
    for j in range(resource_size):
       x.append(int(input()))

    all.append(x)

print('max',max)
print('allocation', all)

print('enter resourses array')
resource = []
for i in range(resource_size):
    resource.append(int(input()))


# max = [
#     [7, 5, 3],
#     [3, 2, 2],
#     [9, 0, 2],
# ]

# all = [
#     [0, 1, 0],
#     [2, 0, 0],
#     [3, 0, 2],
# ]

# resource = [10,5,7] # total resources
need = []


for i in range(process_size):
    needOne =[]
    for j in range(resource_size):
        x = max[i][j] - all[i][j]
        needOne.append(x)
    need.append(needOne)

print('need',need)

ABC = [] # total allocation
for i in range(resource_size):
    x = 0
    for j in range(process_size):
        x += all[j][i]
    ABC.append(x)

print('total allocation',ABC)

available = []
safe = True
for i in range(resource_size):
    x = resource[i] - ABC[i]
    if (x) < 0 :
        Safe = False

    available.append(x)
    
print('available',available)

if not safe:
    print('Not a Safe State ')
