import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Injectable()
export class ConfigService {
	constructor(private http: HttpClient) { }
  
	jsonUrl = 'assets/data/botoes.json';
	
	getJson() {
		return this.http.get(this.jsonUrl);
	}
}