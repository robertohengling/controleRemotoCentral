import { CUSTOM_ELEMENTS_SCHEMA } from '@angular/core';
import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ComandoComponent } from './comando.component';

describe('ComandoComponent', () => {
  let component: ComandoComponent;
  let fixture: ComponentFixture<ComandoComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ComandoComponent ],
      schemas: [CUSTOM_ELEMENTS_SCHEMA],
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ComandoComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
