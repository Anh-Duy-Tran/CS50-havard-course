import sys
import csv

STRs = []
database = []

def main():

    if len(sys.argv) < 3:
        print('Usage python dna.py database.csv sequance.csv')
        sys.exit(1)

    with open(sys.argv[1]) as data:
        data = csv.reader(data)
        for row in data:
            if row[0] == 'name':
                for i in range(1, len(row)):
                    STRs.append(row[i])
            else:
                database.append({})
                database[-1]["name"] = row[0]
                database[-1]["strCount"] = [int(row[i]) for i in range(1, len(row))]


    with open(sys.argv[2]) as s:
        s = s.readline()
        n = len(s)

        count = [0 for _ in range(len(STRs))]
        
        for place, str in enumerate(STRs):
            i = 0
            while i < n:
                current = 0
                tmp = s.find(str, i, len(s))
                if tmp == -1:
                    break
                while(tmp != -1):
                    current += 1
                    i = tmp + 1
                    tmp = s.find(str, i, len(s))
                    if (tmp - i >= len(str) or tmp == -1):
                        count[place] = max(count[place], current)
                        current = 0


    for person in database:
        if count == person["strCount"]:
            return person["name"]

    return "No match"

print(main())