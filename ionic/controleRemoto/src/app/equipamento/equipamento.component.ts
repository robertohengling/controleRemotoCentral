import { Component, OnInit, Input } from '@angular/core';
import { Comando } from '../models/comando';
import { Equipamento } from '../models/equipamento';

@Component({
  selector: 'app-equipamento',
  templateUrl: './equipamento.component.html',
  styleUrls: ['./equipamento.component.scss'],
})
export class EquipamentoComponent implements OnInit {
	@Input() equipamento: Equipamento;
	constructor() { 
	}  
	ngOnInit() {
	}

}
