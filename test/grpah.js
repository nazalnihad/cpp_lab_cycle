const airports = 'PHX BKK OKC JFK LAX MEX EZE HEL LOS LAP LIM'.split(' ');
const route = [
    ['PHX', 'LAX'],
    ['PHX', 'JFK'],
    ['JFK', 'OKC'],
    ['JFK', 'LOS'],
    ['MEX', 'LAX'],
    ['MEX', 'BKK'],
    ['MEX', 'LIM'],
    ['MEX', 'EZE'],
    ['LIM', 'BKK'],
];

const adjacencyList = new Map();
function addNode(airport) {
    adjacencyList.set(airport, []);
}
function addEdge(origin, destination) {
    adjacencyList.get(origin).push(destination);
    adjacencyList.get(destination).push(origin);
}

airports.forEach(addNode);
route.forEach(routes => addEdge(...routes));
// console.log(adjacencyList);

function bfs(start)
{
    const visited = new Set();
    const queue = [start];

    while(queue.length>0){
        const airport = queue.shift();
        const destinations = adjacencyList.get(airport);
        for(const destination of destinations)
        {
            // queue.push(destination);
            if(destination === 'BKK')
            {
                console.log("Found it!");
            }
            if(!visited.has(destination)){
                visited.add(destination);
                queue.push(destination);
                console.log(destination);
            }
        }
    }
}
bfs('PHX');