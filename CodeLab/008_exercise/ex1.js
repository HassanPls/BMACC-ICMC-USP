class Veiculo {

    constructor(marca, modelo) {
        this.marca = marca;
        this.modelo = modelo;
    }

    descrever() {
        throw new Error("Não implementado");
    }
}

class Carro extends Veiculo {

    constructor(marca, modelo, guidao) {
        super.marca = marca;
        super.modelo = modelo;
        this.guidao = guidao
    }

    descrever() {
        console.log(`Carro ${this.marca} do modelo ${this.modelo}`);
    }

    abrirPortas() {
        console.log("Portas abertas");
    }
}

class Moto extends Veiculo {
    
    constructor(marca, modelo) {
        super.marca = marca;
        super.modelo = modelo;
    }

    descrever() {
        console.log(`Moto ${this.marca} do modelo ${this.modelo}`);
    }
}