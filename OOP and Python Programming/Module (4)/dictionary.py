person = {
    "name": "mohammad abdullah",
    "email": "abdullah917828@gmail.com",
    "work": "sikkhito bekar",
    "live": True,
    "age": 21,
    "location": "china",
    "relationship": "in love",
    "love": "sauda",
    "status": "goribs",
    "married status": "miskins",
}

print(person)
print(person["age"])
print(person["name"])
print(person["love"])
print(person.keys())
print(person.values())
person['language'] = 'python'
person['2nd language'] = 'javascript'
person['3nd language'] = 'c'
person['4nd language'] = 'c++'

print(person)


for key, value in person.items():
    print(key,':-', value)
    


