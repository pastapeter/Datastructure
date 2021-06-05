
INF = 9999
matrix = [[INF for col in range(29)] for row in range(29)]
paths = []

station = {'증산' : 0, '디지털미디어시티' : 1, '월드컵경기장' : 2, '마포구청' : 3, '망원':4, '합정':5, '홍대입구':6, '공덕':7, '상수':8, '광흥창':9, '대흥':10,
'마곡나루': 11, '선유도': 12, '국회의사당' : 13, '여의도' : 14, '샛강' : 15, '노량진' : 16, '노들' : 17, '흑석' : 18, '당산' : 19, '영등포구청' : 20, '영등포시장' : 21,
'여의나루' : 22, '마포':23, '문래':24, '신도림':25, '영등포':26, '대방':27, '신길':28 }


class Edge:
    def __init__(self, distance, station1, station2):
        self.distance  = distance
        self.station1 = station1
        self.station2 = station2

EdgeList = []
EdgeList.append(Edge(5,0,1))
EdgeList.append(Edge(7,1,2))
EdgeList.append(Edge(4,2,3))
EdgeList.append(Edge(6,3,4))
EdgeList.append(Edge(8,4,5))
EdgeList.append(Edge(10,5,6))
EdgeList.append(Edge(12,1,6))
EdgeList.append(Edge(14,6,7))
EdgeList.append(Edge(7,5,8))
EdgeList.append(Edge(9,8,9))
EdgeList.append(Edge(3,9,10))
EdgeList.append(Edge(2,10,7))
EdgeList.append(Edge(18,1,11))
EdgeList.append(Edge(11,5,19))
EdgeList.append(Edge(4,19,12))
EdgeList.append(Edge(12,19,13))
EdgeList.append(Edge(24,13,14))
EdgeList.append(Edge(29,14,15))
EdgeList.append(Edge(27,15,16))
EdgeList.append(Edge(21,16,17))
EdgeList.append(Edge(34,17,18))
EdgeList.append(Edge(36,19,20))
EdgeList.append(Edge(17,20,21))
EdgeList.append(Edge(23,21,28))
EdgeList.append(Edge(25,28,14))
EdgeList.append(Edge(18,14,22))
EdgeList.append(Edge(11,22,23))
EdgeList.append(Edge(21,23,7))
EdgeList.append(Edge(8,20,24))
EdgeList.append(Edge(20,24,25))
EdgeList.append(Edge(27,25,26))
EdgeList.append(Edge(13,26,28))
EdgeList.append(Edge(29,28,27))
EdgeList.append(Edge(22,27,16))

def makeMatrix(EdgeList):
   for edge in EdgeList:
       matrix[edge.station1][edge.station1] = 0
       matrix[edge.station1][edge.station2] = edge.distance
       matrix[edge.station2][edge.station1] = edge.distance

            
class Findway:
    
    def __init__(self):
        self.depart = 0
        self.arrive = 0
        self.visited = []
        self.direction = []

    def start(self):
        print("출발역과 도착역을 입력한다.")
        self.depart = input("출발역 : ")
        self.arrive = input("도착역 : ")
    

    def station_list(self, start = '증산'):
        self.visited.append(start)
        print(start)
        for w in station.keys():
            if w not in self.visited and matrix[station[start]][station[w]] is not INF:
                self.station_list(w)

    def backtrack(self, start):
        
        if(start == station[self.depart]):
            paths.append(station[self.depart]) #18
            return
        
        for i in self.direction:
            if start == i[0]:
                paths.append(i[0])
                self.backtrack(i[1])
                break  


    def SPT_linear(self):
        self.visited.clear()
        self.visited = [False for row in range(29)]
        distance = [0 for row in range(29)]
        
        def getsmallIndex(self):
            min = INF
            index = 0
            for i in range(29):
                if(distance[i] < min and self.visited[i] != True):
                    min = distance[i]
                    index = i
            return index 
        
        for i in range(len(distance)):
            distance[i] = matrix[station[self.depart]][i]
        

        self.visited[station[self.depart]] = True
        for i in range(len(distance)-1):
            current = getsmallIndex(self)
            self.visited[current] = True
            if(i == 0):
                for k in range(len(matrix[station[self.depart]])):
                    if(matrix[station[self.depart]][k] != INF and matrix[station[self.depart]][k] != 0):
                        self.direction.append((k, station[self.depart]))
            for j in range(len(station)):
                if self.visited[j] is not True:
                    if(distance[current] + matrix[current][j] < distance[j]):
                        distance[j] = distance[current] + matrix[current][j] #dp-> 기존의 값을 더작은 값으로 갱신한다.
                        self.direction.append((j, current))
                    

            if self.visited[station[self.arrive]] is True:
                self.backtrack(station[self.arrive])
                break
            
        return distance[station[self.arrive]]


def find_key(dict, val):
    return next(key for key, value in dict.items() if value == val)            


print("지하철노선로 시작")
makeMatrix(EdgeList)
startSubway = Findway()
startSubway.station_list()
startSubway.start()
SPT = startSubway.SPT_linear()
print("경로와 거리를 표시한다.")
paths.reverse()
for path in paths:
    stop = find_key(station, path)
    print(stop, end=" ")
print(f"({SPT})")




