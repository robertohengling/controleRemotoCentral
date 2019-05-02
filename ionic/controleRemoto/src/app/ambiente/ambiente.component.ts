import { Component, OnInit, Input } from '@angular/core';
import { Comando } from '../models/comando';
import { Equipamento } from '../models/equipamento';
import { Ambiente } from '../models/ambiente';

@Component({
  selector: 'app-ambiente',
  templateUrl: './ambiente.component.html',
  styleUrls: ['./ambiente.component.scss'],
})
export class AmbienteComponent implements OnInit {
	@Input() ambiente: Ambiente
	constructor() { }
	ngOnInit() {}

}
