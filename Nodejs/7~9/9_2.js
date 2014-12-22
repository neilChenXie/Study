var http = require('http');
var results = [];
var count = 0;

function printResults () {
	  for (var i = 0; i < 3; i++)
		      console.log(results[i]);
}

function httpGet (index) {
	  http.get(process.argv[2 + index], function (response) {
		  	  response.setEncoding('utf8');
			  results[index] = '';
		      response.on('data',function (data) {
				  	//	console.log(data);
				        results[index] += data;

				      });
			  response.on('end', function (){
				        count++;
				        if (count == 3) // yay! we are the last one!
				          printResults();
			  	});
			    });
}

for (var i = 0; i < 3; i++)
  httpGet(i);
