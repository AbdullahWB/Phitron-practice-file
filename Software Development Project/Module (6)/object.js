const person = {
    name: "Mohammad Abdullah",
    age: 21.8,
    job: "Student",
    passion: "Sokher Programmer",
    language: ["c programming", "c++", "python", "javascript"],
    study: "CWNU"
}

console.log(person.name)    
console.log(person.age)
console.log(person.language[1])

for(const p in person){
    console.log(p)
}