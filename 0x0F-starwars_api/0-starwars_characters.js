#!/usr/bin/node
const request = require('request');
const reqFilm = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2] + '/';

function asyncRequest (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) reject(error);
      resolve(body);
    });
  });
}

async function getCharactersOfFilm () {
  try {
    const body = await asyncRequest(reqFilm);
    const FilmRequestBody = body;
    const FilmsObject = JSON.parse(FilmRequestBody);
    const FilmCharacters = FilmsObject.characters;

    for (const k in FilmCharacters) {
      const body = await asyncRequest(FilmCharacters[k]);
      const CharacterRequestBody = body;
      const CharactersObject = JSON.parse(CharacterRequestBody);
      console.log(CharactersObject.name);
    }
  } catch (error) {
    console.error('ERROR:');
    console.error(error);
  }
}

getCharactersOfFilm();
