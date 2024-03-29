Pebble.addEventListener("ready",
  function(e) {
    console.log("JavaScript app ready and running!");
  }
);

Pebble.addEventListener("showConfiguration", function() {
  console.log("showing configuration");
  Pebble.openURL('http://assets.getpebble.com.s3-website-us-east-1.amazonaws.com/pebble-js/configurable.html');
});

Pebble.addEventListener("webviewclosed", function(e) {
  console.log("configuration closed");
  // webview closed
  var options = JSON.parse(decodeURIComponent(e.response));
  console.log("Options = " + JSON.stringify(options));
});