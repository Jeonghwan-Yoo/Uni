(function() {
    "use strict";
    
    var $ = function(id) { return document.getElementById(id); };
    var $$ = function(id) { return document.getElementsByName(id); };
    
    var timer = null;
    var output = [];
    var index = 0;
    
    window.onload = function() {

        $("start").disabled = false; 
        $("stop").disabled = true;
        $("input").disabled = false;

        $("start").onclick = createPassage;
        $("input").onchange = changeText;
        $("stop").onclick = clear;
        for(var i = 0; i < $$("size").length; i++) {
            $$("size")[i].onclick = editSize;
        }
        $("wordspeed").onchange = newTimer;
    };
    
    function createPassage() {
        var input = $("input").value;
        if(output.length < 1) {
            output = input.split(/[ \t\n]+/);
        }
        for(var i = 0; i < output.length; i++) {
            if(output[i].endsWith(",")||output[i].endsWith(".")||output[i].endsWith("!")||
               output[i].endsWith("?")||output[i].endsWith(":")||output[i].endsWith(";")) {
                
                output[i] = output[i].substring(0, output[i].length - 1);
                output.splice(i, 0, output[i]);
                i++;
            }
        }
        createTimer();

        $("start").disabled = true;
        $("stop").disabled = false;
        $("input").disabled = true;
    }
    
    function changeText() {
        output = [];
    }
    
    function clear() {
        $("reader").innerHTML = "";
        index = 0;
        clearInterval(timer);
        
        $("start").disabled = false;
        $("stop").disabled = true;
        $("input").disabled = false;
    }
   
    function createTimer() {
        var wordspeed = $("wordspeed");
        var wpm = wordspeed.children[wordspeed.selectedIndex].value;
        timer = setInterval(read, wpm);
    }
    
    function newTimer() {
        if(!$("stop").disabled) {
            clearInterval(timer);
            createTimer();
        }
    }
    
    function read() {
        var passage = $("reader");
        if(output[index]) {
            passage.innerHTML = output[index];
            index++;
        }else {
            passage.innerHTML = "";
            clear();
        }
    }
    
    function editSize() {
        $("reader").style.fontSize = this.value;
    }
})();