#!/usr/bin/node

const request = require('request');
const args = process.argv[2]
const url = 'https://swapi-api.hbtn.io/api/films/' + args;

request(url, function (error, response, body) {
	if (error) {
		console.log('Error:', error);
		return;
	}

	if (body === '') {
		console.log('No data found');
		return;
	}

	const data = JSON.parse(body)
	data.characters.forEach(element => {
		request(element, function (error, response, body) {
			if (error) {
				console.log('Error:', error);
				return;
			}

			if (body === '') {
				console.log('No data found');
				return;
			}

			const character = JSON.parse(body);
			console.log(character.name);
		});
	});

})
