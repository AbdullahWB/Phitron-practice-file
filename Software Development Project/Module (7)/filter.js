const array = [
    {
        name: "abdullah",
        age: 20
    },
    {
        name: "mohammad",
        age: 21
    },
    {
        name: "sauda",
        age: 19
    },
    {
        name: "busra",
        age: 20
    }
];

const result = array.filter(person => person.age === 20);
console.log(result);