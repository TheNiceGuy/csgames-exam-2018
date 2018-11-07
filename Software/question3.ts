class Beer {
    public name: string;
    public id: string;
    public isAvailable: boolean;
    public IBU: number;
    public beerType: string; //the type of beer
    public percentageOfAlcoholInTheBeerInPercent: number;
    public quantity: number;

    constructor(name: string) {
        this.name = name;
        this.id = this.generateId(name);
        this.isAvailable = true;
        this.IBU = 0;
    }

    public setName(name: string): void {
        this.name = name;
        this.id = this.generateId(name);
    }

    // Replace spaces in the name with dashes
    public generateId(name: string): string {
        return name.replace(/ /g, "-");
    }

    public order(x: number): void {
        if (this.isAvailable == true) {
            this.quantity = this.quantity - x;
        }
    }

    public playSlapCup(player1: string, player2: string, player3: string, player4: string, player5: string, player6: string) {
        console.log("l'oreille droite sur la table");
        var redflag: boolean = false;
        for (let verre = 0; verre <= 3; verre++) {
            if (verre == 3) {
                redflag = true;
            }
        }
    }
}
