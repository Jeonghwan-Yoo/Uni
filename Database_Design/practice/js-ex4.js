window.onload=function(){
	let btn=document.getElementById("myBtn");
	btn.addEventListener("click",displayDate);
	btn.addEventListener("click", createParagraph);
	let p1=4;
	btn.addEventListener("click", function() { biggerFont(p1);})
	
	window.addEventListener("resize", function(){
		document.getElementById("demo").innerHTML="Resized";}
	)
};
function displayDate(){
	document.getElecmentById("demo").innerHTML=Date();
}
function createParagraph(){
	let para=document.createElement('p');
	para.textContent='You clicked the button!';
	document.body.appendChild(para);
}
function biggerFont(a){
	let button=document.getElementById("myBtn");
	let size=parseInt(button.style.fontSize):
	button.style.fontSize=(size+a)+"pt";
}
