import { Component } from '@angular/core';
import { Equipamento } from '../models/equipamento';
import { Ambiente } from '../models/ambiente';
import { Comando } from '../models/comando';
import * as ambientesJson from "./ambientes.json";

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {
	ambientes: Array<Ambiente>;
	constructor() {
		this.ambientes = ambientesJson.default.ambientes;
		console.log(ambientesJson.default)
	}  
}
