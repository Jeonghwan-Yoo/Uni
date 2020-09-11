<!DOCTYPE html>
<html>
  <head>
    <style>
      #map {
        height: 400px;
        width: 100%;
       }
    </style>
  </head>
  <body>
    <h3>My Google Maps Demo</h3>
    <div id="map"></div>
    <script>
      function initMap() {
        var africa = {lat :23.580680, lng : 17.457255};
        var asia = {lat:60.306447, lng : 97.098467};
        var europe = {lat: 53.077932, lng : 17.881003};
        var america = {lat : 49.245250, lng : -106.118137};
        var ct = {lat : 20.803080, lng : 155.048936};

        var map = new google.maps.Map(document.getElementById('map'), {
          zoom: 1.4,
          center: ct
        });        
                
        var marker = new google.maps.Marker({
           position : africa,
           map: map
           });
        
        marker.addListener('click', function() {
           location.href="africa_arabia.jsp";
           });
        
        var marker = new google.maps.Marker({
           position : asia,
           map: map
           });
        
        marker.addListener('click', function() {
           location.href="asia_oceania.jsp";
           });
        
        var marker = new google.maps.Marker({
           position : europe,
           map: map
           });
            
            marker.addListener('click', function() {
               location.href="europe.jsp";
              });
            
            var marker = new google.maps.Marker({
               position : america,
               map: map
            });
            
            marker.addListener('click', function() {
               location.href="americas.jsp";
              });
            
          }
        </script>
    <script async defer
    src="https://maps.googleapis.com/maps/api/js?key=AIzaSyBLYdDbZaZL65Vy4cQZh4dGBI-mwgCqHX8&callback=initMap">
    </script>
  </body>
</html>