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

person = array.find(arr => arr.name == 'sauda');
console.log(person);