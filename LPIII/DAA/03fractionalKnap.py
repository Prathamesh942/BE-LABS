def fractionalKnap(items, capacity):
    profit = 0.0
    items.sort(key = lambda x:x[0]/x[1], reverse=True)
    for item in items:
        if capacity>item[1]:
            profit+=item[0]
            capacity-=item[1]
        else:
            profit+=capacity*item[0]/item[1]
            break
    print(profit)

items = [(60, 10), (100, 20), (120, 30)]

fractionalKnap(items, 50)