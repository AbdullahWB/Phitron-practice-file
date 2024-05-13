def double_decker():
    print("Print from double decker")
    def inner_decker():
        print("Print from inner decker")
        return 369
    return inner_decker

# print(double_decker())
# print(double_decker()())

def coding(do):
    # print(do)
    print("coding is my life")
    return do

def do_something():
    return "do_something"
    
print(coding(do_something()))