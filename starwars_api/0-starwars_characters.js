#!/usr/bin/node

const request = require('request');
const filmId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${filmId}`;

function getData (url) {
  return new Promise((resolve, reject) => {
    request(url, (err, res, body) => {
      if (err) return reject(err);
      try {
        const data = JSON.parse(body);
        resolve(data);
      } catch (parseError) {
        reject(parseError);
      }
    });
  });
}

getData(url)
  .then(async (film) => {
    for (const characterUrl of film.characters) {
      const character = await getData(characterUrl);
      console.log(character.name);
    }
  })
  .catch((err) => {
    console.error('Error:', err.message);
  });
