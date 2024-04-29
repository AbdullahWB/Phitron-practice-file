taka=20000

def kinakata(item1, item2):
    total = item1 + item2
    global taka #use global keyword for use globally variable
    have=taka-total
    print(f'total kinakata korce{total} taka ace {have}')

kinakata(1200, 3000)