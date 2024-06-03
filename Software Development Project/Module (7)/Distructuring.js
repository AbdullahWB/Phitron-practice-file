const person = {
    name: "Mohammad Abdullah",
    age: 21.8,
    job: "Student",
    passion: "Sokher Programmer",
    language: ["c programming", "c++", "python", "javascript"],
    study: "CWNU"
}

const {name, age, job, passion, language, study} = person

console.log(name);
console.log(age);
console.log(job);
console.log(passion);
console.log(language);
console.log(study);

console.log(" \n\n");


const abdullah = ["Mohammad Abdullah", 21.8, "Sokher Programmer"]
const [name1, age1, passion1] = abdullah
console.log(name1);
console.log(age1);
console.log(passion1);