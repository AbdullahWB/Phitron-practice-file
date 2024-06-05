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

const result = array.map((arr) => arr.name);
console.log(result);

const posts = [
  {
    id: 1,
    title: "Sample Title 1",
    description: "Lorem ipsum dolor sit amet, consectetur adipiscing elit...",
  },
  {
    id: 2,
    title: "Sample Title 2",
    description: "Lorem ipsum dolor sit amet, consectetur adipiscing elit...",
  },
  {
    id: 3,
    title: "Sample Title 3",
    description: "Lorem ipsum dolor sit amet, consectetur adipiscing elit...",
  },
];
// ES2016+
// Create new array of post IDs. I.e. [1,2,3]
const postIds = posts.map((post) => post.id);
console.log(postIds);
// Create new array of post objects. I.e. [{ id: 1, title: "Sample Title 1" }]
const postSummaries = posts.map((post) => ({ id: post.id, title: post.title }));
console.log(postSummaries);


const avengers = ['thor', 'captain america', 'hulk'];
avengers.forEach((item, index)=>{
	console.log(index, item)
})