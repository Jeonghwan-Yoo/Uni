window.onload=function(){
	document.getElementById("textbox").onkeydown=textKeyDown;
};
function textKeyDown(event){
	let code=event.keyCode;
	let key=String.fromCharCode(event.keyCode);
	document.getElementById("demo").innerHTML=key+" ("+code+")";
	
	if(key=='x'&&event.shiftKey){
	alert("Input the large X!");
	this.value=this.value.split("").join("-");
	}
}