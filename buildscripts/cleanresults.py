data = open('results.log', 'r').readlines()
data2 = ""
counter = 0
for line in data:
    if line.find('<?xml') != -1:
        if counter > 0:
            open('results' + str(counter) + '.xml', 'w').write(data2)
            data2 = ""
        counter = counter + 1    
    data2 = data2 + line
open('results' + str(counter+1) + '.xml', 'w').write(data2)
