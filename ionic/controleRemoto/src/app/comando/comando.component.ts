import { Component, OnInit, Input } from '@angular/core';
import { Comando } from '../models/comando' ;
import { HttpClient } from '@angular/common/http';

@Component({
  selector: 'app-comando',
  templateUrl: './comando.component.html',
  styleUrls: ['./comando.component.scss'],
})
export class ComandoComponent implements OnInit {
	@Input() comando:Comando;
	
	constructor(public httpClient: HttpClient) { 
	}  
	ngOnInit() {  
	}  
	send(){
		var headers = new Headers();
		headers.append("Accept", 'application/json');
		headers.append('Content-Type', 'application/json' );

		this.httpClient.post("http://192.168.15.177", this.comando.comando)
		  .subscribe(data => {
			console.log(data['_body']);
		   }, error => {
			console.log(error);
		  });
	}
}
