#!/usr/bin/env node
const request = require('request');
const reqFilm = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2] + '/';

request(reqFilm, (error, response, body) => {
  if (error) console.error('error:', error);
  const FilmRequestBody = body;
  const FilmsObject = JSON.parse(FilmRequestBody);
  const FilmCharacters = FilmsObject.characters;

  for (const k in FilmCharacters) {
    request(FilmCharacters[k], function (error, response, body) {
      if (error) console.error('error:', error);
      const CharacterRequestBody = body;
      const CharactersObject = JSON.parse(CharacterRequestBody);
      console.log(CharactersObject.name);
    });
  }
});
