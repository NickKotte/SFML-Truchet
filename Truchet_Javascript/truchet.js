var GRIDSIZE = 25;
var TILESIZE = 30;
var patterns = [];
function setup(){
	createCanvas(windowWidth,windowHeight);
	background(100);
	console.log(GRIDSIZE)
	GRIDSIZE = windowWidth/TILESIZE/2;
	console.log(GRIDSIZE)
	let offset = TILESIZE
	noFill()
	translate(offset, offset)
	stroke(255)
	for (let i = 0; i < GRIDSIZE; i++){
		patterns.push([]);
		for (let j = 0; j < GRIDSIZE; j++){
			patterns[i][j] = new DualArc(i, j, TILESIZE*2);
		}
	}
}

var dir = 1;
function draw() {
	background(0)

	randx = random(0, GRIDSIZE) | 0
	randy = random(0, GRIDSIZE) | 0
	patterns[randx][randy].invert()
	for (let i = 0; i < GRIDSIZE; i++){
		for (let j = 0; j < GRIDSIZE; j++){
			patterns[i][j].draw();
		}
	}	
}