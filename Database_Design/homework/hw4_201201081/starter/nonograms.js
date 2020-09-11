(function() {
  "use strict";

  var down = false;
  var currentType = "";
  
  window.onload = function() {
    generateCols();
    generateGrid();
    generateRows();
    setUpTiles();
    window.onmouseup = function() {
      currentType = "";
      down = false;
    };
    $("clear").onclick = clearPuzzle; 
  };
  function generateCols() {
    return $("top-nums");
    return $$("top-nums");
  }
  function generateRows() {
    return $("left-nums");
  }
  function generateGrid() {
    return $("grid");
  }  
  function setUpTiles() {
    var tiles = $$(".box");
    for (var i = 0; i < tiles.length; i++) {
      var div = tiles[i];
      div.onmousedown = function() {
        down = true;
        if (this.classList.contains("filled")) {
          this.classList.remove("filled");
          this.classList.add("crossed-out");
          currentType = "crossed-out";
        } else if (this.classList.contains("crossed-out")) {
          this.classList.remove("crossed-out");
          currentType = "";
        } else {
          this.classList.add("filled");
          currentType = "filled";
        }
      };

      div.onmouseover = function() {
        if (down) {
          if (currentType == "") {
            this.classList.remove("crossed-out");
          } else if (currentType == "filled") {
            this.classList.add("filled");
            this.classList.remove("crossed-out");
          } else { 
            this.classList.add("crossed-out");
            this.classList.remove("filled");
          }
        }
      };
      div.onclick = function() {
          down = false;
          currentType = "";
      };
    }
  }
  function clearPuzzle() {
      if (confirm("Are you sure you want to clear the puzzle?")) {
    
        var boxes = $$(".box");
        for (var i = 0; i < boxes.length; i++) {
          boxes[i].classList.remove("filled", "crossed-out");
        }
      }
  }

  function $(id) {
    return document.getElementById(id);
  }

  function $$(query) {
    return document.querySelectorAll(query);
  }
})();